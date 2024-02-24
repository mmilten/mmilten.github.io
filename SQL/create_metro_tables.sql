DROP SEQUENCE rider_id_seq;
DROP SEQUENCE discount_id_seq;
DROP SEQUENCE card_id_seq;
DROP SEQUENCE transaction_id_seq;
DROP SEQUENCE station_id_seq;
DROP SEQUENCE trip_id_seq;
DROP SEQUENCE line_id_seq;
DROP SEQUENCE schedule_id_seq;

DROP TABLE schedule_station;
DROP TABLE schedule;
DROP TABLE line_station;
DROP TABLE train_line;
DROP TABLE trips;
DROP TABLE station;
DROP TABLE transactions;
DROP TABLE metro_card;
DROP TABLE discounts;
DROP TABLE riders;
 
create table riders
(
  rider_id        NUMBER          NOT NULL,
  email           VARCHAR2(30)    NOT NULL,
  password        VARCHAR2(30)    NOT NULL,
  riders_name     VARCHAR2(30)    NOT NULL,
  riders_age      NUMBER          NOT NULL,
  constraint riders_pk
  primary key (rider_id)
);

create table discounts
(
  discount_id 		NUMBER          NOT NULL,
  discount_name 	VARCHAR2(30)	NOT NULL,
  constraint discounts_pk
  primary key (discount_id)
);

create table metro_card
(
  card_id         NUMBER        NOT NULL,
  balance         NUMBER(9,2)   NOT NULL,
  discount_id     NUMBER        NOT NULL,
  rider_id        NUMBER        NOT NULL,
  constraint card_pk
  primary key (card_id),
  constraint metro_card_fk_riders
  foreign key (rider_id) references riders (rider_id),
  constraint metro_card_fk_discounts
  foreign key (discount_id) references discounts (discount_id)
);



create table transactions
(
  transaction_id      NUMBER      NOT NULL,
  card_id             NUMBER      NOT NULL,
  transaction_time    TIMESTAMP   NOT NULL,
  amount              NUMBER(9,2) NOT NULL,
  constraint transactions_pk
  primary key (transaction_id),
  constraint transactions_fk_card
  foreign key (card_id) references metro_card (card_id)
); 

create table station
(
  station_id          NUMBER          NOT NULL,
  station_name        VARCHAR2(30)    NOT NULL,			
  station_address     VARCHAR2(30)    NOT NULL,
  station_status      VARCHAR2(5)     NOT NULL,
  constraint stations_pk
  primary key (station_id)
);

create table trips
(
  trip_id         NUMBER        NOT NULL,
  card_id         NUMBER        NOT NULL,
  entrance_id     NUMBER        NOT NULL,
  exit_id         NUMBER        NOT NULL,
  entrance_time   TIMESTAMP     NOT NULL,
  exit_time       TIMESTAMP     NOT NULL,	
  cost            NUMBER(9,2)   NOT NULL,
  constraint trips_pk
  primary key (trip_id),
  constraint trips_fk_metro_card
  foreign key (card_id) references metro_card (card_id),
  constraint trips_fk_entrance
  foreign key (entrance_id) references station (station_id),
  constraint trips_fk_exit
  foreign key (exit_id) references station (station_id)
    
);

create table train_line
(
  line_id         NUMBER          NOT NULL,
  line_name       VARCHAR2(30)    NOT NULL,
  line_number     NUMBER          NOT NULL,
  constraint line_pk
  primary key (line_id)
);

create table line_station
(
  line_id               NUMBER  NOT NULL,
  station_id            NUMBER  NOT NULL,
  sequence_number       NUMBER  NOT NULL,
  constraint line_station_pk
  primary key (line_id, station_id),
  constraint line_station_fk_line
  foreign key (line_id) references train_line (line_id),
  constraint line_station_fk_station
  foreign key (station_id) references station (station_id)
);

create table schedule
(
  schedule_id     NUMBER    NOT NULL,
  line_id         NUMBER    NOT NULL,
  direction       NUMBER    NOT NULL,
  constraint schedule_pk
  primary key (schedule_id),
  constraint schedule_fk_line
  foreign key (line_id) references train_line (line_id)
);

create table schedule_station
(
  schedule_id         NUMBER                  NOT NULL,
  station_id          NUMBER                  NOT NULL,
  schedule_arrival    INTERVAL DAY TO SECOND  NOT NULL,
  constraint schedule_station_pk
  primary key (schedule_id, station_id),
  constraint schedule_station_fk_schedule
  foreign key (schedule_id) references schedule (schedule_id),
  constraint schedule_station_fk_station
  foreign key (station_id) references station (station_id)	
);

--Create the sequence
CREATE SEQUENCE rider_id_seq
  START WITH 1;
CREATE SEQUENCE discount_id_seq
  START WITH 1;
CREATE SEQUENCE card_id_seq
  START WITH 1;
CREATE SEQUENCE transaction_id_seq
  START WITH 1;
CREATE SEQUENCE station_id_seq
  START WITH 1;
CREATE SEQUENCE trip_id_seq
  START WITH 1;
CREATE SEQUENCE line_id_seq
  START WITH 1;
CREATE SEQUENCE schedule_id_seq
  START WITH 1;

-- INSERT INTO riders
INSERT INTO riders
(rider_id, email, password, riders_name, riders_age)
VALUES (rider_id_seq.nextval, 'jwalton1@gmail.com', 'Jwal0009!', 'John Walton', 25);
INSERT INTO riders
(rider_id, email, password, riders_name, riders_age)
VALUES (rider_id_seq.nextval, 'falberto1@gmail.com', 'Fran549!!', 'Francesco Alberto', 60);
INSERT INTO riders
(rider_id, email, password, riders_name, riders_age)
VALUES (rider_id_seq.nextval, 'kquinn@gmail.com', 'Quin998!', 'Kenzie Quinn', 12);

-- INSERT INTO discounts
INSERT INTO discounts (discount_id, discount_name) VALUES (discount_id_seq.nextval, 'Regular');
INSERT INTO discounts (discount_id, discount_name) VALUES (discount_id_seq.nextval, 'Children');
INSERT INTO discounts (discount_id, discount_name) VALUES (discount_id_seq.nextval, 'Senior');

-- INSERT INTO metro_card
INSERT INTO metro_card (card_id, balance, discount_id, rider_id) VALUES (card_id_seq.nextval, 50, 1, 1);
INSERT INTO metro_card (card_id, balance, discount_id, rider_id) VALUES (card_id_seq.nextval, 10, 3, 2);
INSERT INTO metro_card (card_id, balance, discount_id, rider_id) VALUES (card_id_seq.nextval, 5, 2, 3);

-- INSERT INTO transactions
INSERT INTO transactions
(transaction_id, card_id, transaction_time, amount) VALUES (transaction_id_seq.nextval, 1, timestamp '20-02-20 06:30:16', 10);
INSERT INTO transactions
(transaction_id, card_id, transaction_time, amount) VALUES (transaction_id_seq.nextval, 1, timestamp '22-02-20 04:30:16', 10);
INSERT INTO transactions
(transaction_id, card_id, transaction_time, amount) VALUES (transaction_id_seq.nextval, 2, timestamp '24-02-20 06:30:16', 5);

-- INSERT INTO station
INSERT INTO station
(station_id, station_name, station_address, station_status)
VALUES (station_id_seq.nextval, 'Owings Mills Station', '5018 Painters Mill Rd', 'open');
INSERT INTO station
(station_id, station_name, station_address, station_status)
VALUES (station_id_seq.nextval, 'Greenbelt Station', '5717 Greenbelt Metro Dr', 'open');
INSERT INTO station
(station_id, station_name, station_address, station_status)
VALUES (station_id_seq.nextval, 'Union Station', '701 First St NE', 'open');
INSERT INTO station
(station_id, station_name, station_address, station_status
VALUES (station_id_seq.nextval, 'College Park Station', '4931 Calvert Rd', 'open');
INSERT INTO station
(station_id, station_name, station_address, station_status)
VALUES (station_id_seq.nextval, 'Fort Totten Station', '550 Galloway St', 'open');
INSERT INTO station
(station_id, station_name, station_address, station_status)
VALUES (station_id_seq.nextval, 'Rockville Station', '307 South Stonestreet Ave', 'open');


-- INSERT INTO trips
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 1, 1, 3, timestamp '20-02-20 06:30:16', timestamp '20-02-20 7:30:30', 10);
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 1, 3, 1, timestamp '20-02-20 16:30:16', timestamp '20-02-20 17:30:30', 10);
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 2, 2, 3, timestamp '20-02-20 07:30:16', timestamp '20-02-20 08:00:30', 5);
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 2, 2, 3, timestamp '20-02-20 07:30:16', timestamp '20-02-20 08:00:30', 10);
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 3, 2, 3, timestamp '20-02-20 07:30:16', timestamp '20-02-20 08:00:30', 10);
INSERT INTO trips
(trip_id, card_id, entrance_id, exit_id, entrance_time, exit_time, cost)
VALUES (trip_id_seq.nextval, 3, 3, 4, timestamp '20-02-20 07:30:16', timestamp '20-02-20 08:00:30', 10);

-- INSERT INTO train_line
INSERT INTO train_line (line_id, line_name, line_number) VALUES (line_id_seq.nextval, 'Red line', 4);
INSERT INTO train_line (line_id, line_name, line_number) VALUES (line_id_seq.nextval, 'Green line', 4);
INSERT INTO train_line (line_id, line_name, line_number) VALUES (line_id_seq.nextval, 'Yellow line', 3);

-- INSERT INTO line_station
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (1, 1, 1);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (1, 2, 2);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (1, 3, 3);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (1, 4, 4);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (2, 3, 1);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (2, 5, 2);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (2, 4, 3);
INSERT INTO line_station (line_id, station_id, sequence_number) VALUES (2, 6, 4);



-- INSERT INTO schedule
INSERT INTO schedule (schedule_id, line_id, direction) VALUES (schedule_id_seq.nextval, 1, 1);
INSERT INTO schedule (schedule_id, line_id, direction) VALUES (schedule_id_seq.nextval, 2, 2);


-- INSERT INTO schedule_station
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (1, 1, INTERVAL '06:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (1, 2, INTERVAL '07:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (1, 3, INTERVAL '08:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (1, 4, INTERVAL '09:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (2, 3, INTERVAL '07:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (2, 5, INTERVAL '09:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (2, 4, INTERVAL '11:30' HOUR TO MINUTE);
INSERT INTO schedule_station
(schedule_id, station_id, schedule_arrival)
VALUES (2, 6, INTERVAL '13:30' HOUR TO MINUTE);

COMMIT;