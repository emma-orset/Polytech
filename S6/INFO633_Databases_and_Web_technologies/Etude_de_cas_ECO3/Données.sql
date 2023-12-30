-- zones

# NB : utiliser un alias dans le select imbriqué pour éviter l’erreur « référence circulaire »



INSERT INTO zone (nom) VALUES ('Polytech') ;



INSERT INTO zone (nom, id_zone_container) VALUES ('A', (select z.id_zone from zone z where z.nom like 'Polytech')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('B', (select z.id_zone from zone z where z.nom like 'Polytech')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C', (select z.id_zone from zone z where z.nom like 'Polytech')) ;





INSERT INTO zone (nom, id_zone_container) VALUES ('RDC', (select z.id_zone from zone z where z.nom like 'A')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('Etage 1', (select z.id_zone from zone z where z.nom like 'A')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('Etage 2', (select z.id_zone from zone z where z.nom like 'A')) ;



INSERT INTO zone (nom, id_zone_container) VALUES ('C213', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C214', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C215', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C216', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C217', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C209', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;

INSERT INTO zone (nom, id_zone_container) VALUES ('C210', (select z.id_zone from zone z where z.nom like 'Etage 2')) ;





-- capteurs



INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('co213', (select id_zone from zone where nom like 'C213'), 'CO2', 'ppm', 300, 3000) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('co214', (select id_zone from zone where nom like 'C214'), 'CO2', 'ppm', 300, 3000) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('co215', (select id_zone from zone where nom like 'C215'), 'CO2', 'ppm', 300, 3000) ;



INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp3', (select id_zone from zone where nom like 'C210'), 'temperature', 'degre', 6, 40) ;



INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp210', (select id_zone from zone where nom like 'C210'), 'temperature', 'degre', 6, 40) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp209', (select id_zone from zone where nom like 'C209'), 'temperature', 'degre', 6, 40) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp214', (select id_zone from zone where nom like 'C214'), 'temperature', 'degre', 6, 40) ;



INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp217', (select id_zone from zone where nom like 'C217'), 'temperature', 'degre', 6, 40) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('temp215', (select id_zone from zone where nom like 'C215'), 'temperature', 'degre', 6, 40) ;



INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('hygro210', (select id_zone from zone where nom like 'C210'), 'humidite', '%', 20, 100) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('hygro209', (select id_zone from zone where nom like 'C209'), 'humidite', '%', 20, 100) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('hygro217', (select id_zone from zone where nom like 'C217'), 'humidite', '%', 20, 100) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('hygro214', (select id_zone from zone where nom like 'C214'), 'humidite', '%', 20, 100) ;

INSERT INTO capteur (nom, id_zone, type_capteur, unite, valmin, valmax) VALUES ('hygro215', (select id_zone from zone where nom like 'C215'), 'humidite', '%', 20, 100) ;



-- actionneurs



INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('vnc0', 'moteur', 'vnc0 : ventilation', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('vnc2', 'moteur', 'vnc2 : ventilation', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('rad1', 'graduateur', 'rad1 : chauffage', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('rad2', 'graduateur', 'rad2 : chauffage', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('rad3', 'graduateur', 'rad3 : chauffage', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('rad4', 'graduateur', 'rad4 : chauffage', DEFAULT) ;



INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('volet1', 'moteur', 'volet1', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('volet2', 'moteur', 'volet2', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('volet3', 'moteur', 'volet3', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('volets4-5', 'moteur', 'volets4-5', DEFAULT) ;

INSERT INTO actionneur (nom, type_actionneur, description, etat) VALUES ('volets6-7', 'moteur', 'volets6-7', DEFAULT) ;





INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'vnc0'), (select id_zone from zone where nom like 'C213')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'vnc2'), (select id_zone from zone where nom like 'C214')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'rad1'), (select id_zone from zone where nom like 'C213')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'rad2'), (select id_zone from zone where nom like 'C214')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'rad2'), (select id_zone from zone where nom like 'C215')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'rad2'), (select id_zone from zone where nom like 'C216')) ;



INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volet1'), (select id_zone from zone where nom like 'C213')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volet2'), (select id_zone from zone where nom like 'C214')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volet3'), (select id_zone from zone where nom like 'C215')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volets4-5'), (select id_zone from zone where nom like 'C209')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volets4-5'), (select id_zone from zone where nom like 'C210')) ;



INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volets6-7'), (select id_zone from zone where nom like 'C216')) ;

INSERT INTO actionneur2zone VALUES ((select id_actionneur from actionneur where nom like 'volets6-7'), (select id_zone from zone where nom like 'C217')) ;





-- mesures

-- SELECT Date(current_timestamp) ; -- renvoie la date du jour sans l'heure

-- SELECT timestampadd(MONTH, -1, current_timestamp()); -- soustrait 1h à current_timestamp


/* dates automatisées : s'adaptent au jour */

-- aujourdhui

select @aujourdhui := date(now());

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 4, @aujourdhui), 820) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 8, @aujourdhui), 9000) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 0, @aujourdhui), 9800) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 4, @aujourdhui), 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 8, @aujourdhui), 35) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 4, @aujourdhui), 2500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 8, @aujourdhui), 330) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 0, @aujourdhui), 830) ;


-- hier

select @hier := timestampadd(DAY, -1, date(now()));

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), @hier , 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 4, @hier), 35) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 8, @hier), 2500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 12, @hier), 330) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 16, @hier), 830) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 20, @hier), 35) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 8, @hier), 2500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 12, @hier), 330) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 16, @hier), 14) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 20, @hier), 14) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 8, @hier), 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 12, @hier), 25) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 16, @hier), 25) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 20, @hier), 33) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 4, @hier), 30) ;


-- avant hier

select @avanthier := timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(now()))));

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), @avanthier, 12) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 4, @avanthier), 10) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 8, @avanthier), 10) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 12, @avanthier), 12) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 16, @avanthier), 25) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 20, @avanthier), 24) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 22, @avanthier), 52) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 23, @avanthier), 40) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 4, @avanthier), 18) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 8, @avanthier), 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 12, @avanthier), 30) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 16, @avanthier), 34) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp214'), timestampadd(HOUR, 20, @avanthier), 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), @avanthier , 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 4, @avanthier), 40) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 8, @avanthier), 2500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 12, @avanthier), 330) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 16, @avanthier), 830) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 20, @avanthier), 35) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 8, @avanthier), 2500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co214'), timestampadd(HOUR, 12, @avanthier), 330) ;


-- deux jours avant

select @2joursavant := timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(now()))))));

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 8, @2joursavant), 42) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 12, @2joursavant), 25) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'temp215'), timestampadd(HOUR, 20, @2joursavant), 25) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 8, @2joursavant), 20) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 10, @2joursavant), 40) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro215'), timestampadd(HOUR, 12, @2joursavant), 80) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro214'), timestampadd(HOUR, 14, @2joursavant), 99) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'hygro214'), timestampadd(HOUR, 16, @2joursavant), 75) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 12, @2joursavant), 5000) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 14, @2joursavant), 1500) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 16, @2joursavant), 300) ;


-- trois jours avant

select @3joursavant := timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(timestampadd(DAY, -1, date(now()))))))));

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 8, @3joursavant), 820) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 12, @3joursavant), 9000) ;

INSERT INTO mesure (id_capteur, instant,valeur) VALUES ((select id_capteur from capteur where nom like 'co215'), timestampadd(HOUR, 14, @3joursavant), 9800) ;

