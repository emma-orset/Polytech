-- Fonctions, procédures, déclencheurs

-- 1. Pour une zone dont le nom est donné en paramètre, écrire et tester une procédure qui 
-- affiche le nom de la zone, les capteurs et actionneurs impliqués. Ces informations seront 
-- stockées par la procédure dans une table « capt_act_zone ».

drop procedure if exists capteurs_actionneurs_zone;
delimiter ;;
create procedure capteurs_actionneurs_zone(nomzone varchar(10))
  begin
    drop table if exists capt_act_zone;
    create table capt_act_zone(nomzone varchar(10), nom varchar(10), type varchar(10));
    insert into capt_act_zone
    select nomzone, nom, 'capteur' as type
    from capteur
    where id_zone = (select id_zone from zone where nom like nomzone)
    union
    select nomzone, nom, 'actionneur' as type
    from actionneur2zone az JOIN actionneur a ON az.id_actionneur=a.id_actionneur
    where id_zone = (select id_zone from zone where nom like nomzone)
    order by nom, type;
end;;

call capteurs_actionneurs_zone('C215');;
select * from capt_act_zone;


-- 2. Définir et tester une procédure qui stocke dans une table zones_sans_confort les zones n'ayant pas satisfait les valeurs de confort 
-- données (température < 19, humidité entre 30% et 70%, CO2 > 500ppm) le mois dernier (voir les fonctions date() et to_char() de sql).

drop procedure if exists trouver_zones_sans_confort;
delimiter ;;
create procedure trouver_zones_sans_confort()
  begin
    drop table if exists zones_sans_confort;
    create table zones_sans_confort (nomzone varchar(10), nomcapteur varchar(10), valeurmesuree numeric, instantmesure timestamp);
 
    insert into zones_sans_confort select z.nom, c.nom, m.valeur, m.instant 
            from mesure m JOIN capteur c ON m.id_capteur = c.id_capteur JOIN zone z ON z.id_zone=c.id_zone 
            where (m.instant between (SELECT timestampadd(MONTH, -1, now())) and now()) 
            # ou Timestamp(DAY, -30, now())
                   and ((c.type_capteur like 'temperature' and m.valeur < 19) 
	                 or (c.type_capteur like 'humidite' and m.valeur between 30 and 70) 
 	                 or (c.type_capteur like 'CO2' and m.valeur > 500));
   end;;

call trouver_zones_sans_confort;;
select * from zones_sans_confort;


-- 3. Définir et tester une fonction qui affiche la moyenne des mesures 
-- pour un capteur donné en argument (par exemple pour le capteur temp215).

drop function if exists moyenne_capteur;
delimiter ;;
create function moyenne_capteur(nomcapt varchar(10))
returns decimal(5,2)
  begin
      declare vmoy decimal(5,2);
      select round(avg(m.valeur),2) into vmoy
      from mesure m JOIN capteur c ON m.id_capteur = c.id_capteur
      group by m.id_capteur, c.nom
      having c.nom = nomcapt;
  return vmoy;
  end ;;

select moyenne_capteur("temp215");;   -- l'appel à fonction diffère de celui à procédure


-- 4. Définir et tester une fonction qui affiche le nombre de zones contenues dans 
-- une zone dont le nom est donné en paramètre.

drop function if exists nbsszones_zone;
delimiter ;;
create function nbsszones_zone(nomzone varchar(10))
returns integer
  begin
      declare vnb integer;
      select count(id_zone) into vnb
      from zone z 
      where z.id_zone_container = (select id_zone from zone where nom = nomzone);
  return vnb;
  end ;;

select nbsszones_zone("Polytech");;   -- l'appel à fonction diffère de celui à procédure


-- 5. Créer dans une table compteur_mesures avec une colonne ref_capteur qui fait référence 
-- à id_capteur de capteur et une colonne nommée nbmesures de type entier. Remplir cette table avec 
-- les capteurs contenus dans capteur et la valeur 0 dans nbmesures (insert into … select...). 
-- Ensuite définir et tester un déclencheur qui après chaque mesure insérée incrémente la valeur nbmesures 
-- du capteur concerné dans la table compteur_mesures.

drop table if exists compteur_mesures;

create table compteur_mesures (ref_capteur integer references capteur(id_capteur), 
                               nbmesures integer);
insert into compteur_mesures select id_capteur, 0 from capteur ;

DROP TRIGGER if exists after_insert_mesure;
delimiter ;;
CREATE TRIGGER after_insert_mesure AFTER INSERT
ON mesure FOR EACH ROW
Begin
update compteur_mesures set nbmesures = nbmesures +1
where ref_capteur = New.id_capteur;
End;;

insert into mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 4, @aujourdhui), 720) ;

select * from compteur_mesures;


-- 6. Définir et tester un déclencheur qui avant de modifier le nom d'un capteur, doit vérifier 
-- que le nouveau nom n'existe pas déjà (autre façon de définir une contrainte d'unicité sur le nom de capteur).

DROP TRIGGER if exists before_update_capteur;
delimiter ;;
CREATE TRIGGER before_update_capteur BEFORE UPDATE
ON capteur FOR EACH ROW
Begin
IF NEW.nom in (select nom from capteur) THEN
    set New.nom = Old.nom;   
END IF;
End;;

update capteur set nom = "co215" where id_capteur = 1;
update capteur set nom = "co2150" where id_capteur = 1;
update capteur set nom = "co213" where id_capteur = 1;

select * from capteur where nom like "co213" ;

----