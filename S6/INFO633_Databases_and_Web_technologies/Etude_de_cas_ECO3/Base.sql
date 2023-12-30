drop table if exists mesure cascade;
drop table if exists capteur cascade;
drop table if exists actionneur cascade;
drop table if exists zone cascade;
drop table if exists actionneur2zone cascade;

create table mesure(id_mesure integer auto_increment primary key,
		  id_capteur integer,
		  instant timestamp,
		  valeur numeric) ;


create table capteur(id_capteur integer auto_increment primary key,
		    nom varchar(10),
		    id_zone integer,
		    type_capteur varchar(30),
		    unite varchar(5),
		    valmin numeric,
		    valmax numeric) ;


create table actionneur(id_actionneur integer auto_increment primary key,
		         nom varchar(10),
			 type_actionneur varchar(30),
			 description varchar(50),
			 etat varchar(10) DEFAULT 'OFF');


create table zone(id_zone integer auto_increment primary key,
		   nom varchar(10),
		   id_zone_container integer,
		   gpsX numeric,
		   gpsY numeric,
		   longueur numeric,
		   largeur numeric);


create table actionneur2zone(id_actionneur integer,
		             id_zone integer);

