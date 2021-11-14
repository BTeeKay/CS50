-- Keep a log of any SQL queries you execute as you solve the mystery.
-- I am going to start by getting the schema of the whole database and
-- saving it in a notepad for reference, instead of individual schemas
-- of each table
sqlite3 fiftyville.db
.scehma
-- as per walktrough video, starting with crime scene report of july 28 2020
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND
year = 2020 AND street = 'Chamberlin Street';
--
--description
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time
--— each of their interview transcripts mentions the courthouse.
-- Next I want to see what the three interviews from the day say
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND
year = 2020;
-- The three Interviews that relate to the crime are from Ruth, Eugene, Raymond.
-- I have saved the transcripts in a word doc
-- Eugene recognises the theif and seen them at an ATM on Fifer Street before theft
-- Ruth says The car with the theif left the courtroom within 10 minutes of theft
-- raymond says the thief is planning to take the earliest flight on the 29th july
-- Ill start with the earliest flight to see where the theif may have went
SELECT * FROM airports
WHERE city = 'Fiftyville';
--id | abbreviation | full_name | city
--8 | CSF | Fiftyville Regional Airport | Fiftyville
SELECT * FROM flights
WHERE day = 29 AND month = 7 AND year = 2020 AND
origin_airport_id = (SELECT airports.id FROM airports WHERE city = 'Fiftyville');
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
-- 23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- 43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30
-- 53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20
-- the earliest flight is 8:20 going to destination airport id 4
SELECT * FROM airports
WHERE id = 4;
-- id | abbreviation | full_name | city
-- 4 | LHR | Heathrow Airport | London
-- I believe the theif was on the flight to London, we can get a list of suspects
-- from the passenger manifest
SELECT * FROM passengers
WHERE flight_id = 36;
-- flight_id | passport_number | seat
-- 36 | 7214083635 | 2A
-- 36 | 1695452385 | 3B
-- 36 | 5773159633 | 4A
-- 36 | 1540955065 | 5C
-- 36 | 8294398571 | 6C
-- 36 | 1988161715 | 6D
-- 36 | 9878712108 | 7A
-- 36 | 8496433585 | 7B
-- we need to now take the passenger numbers from flight 36 and get names
-- if we do this with wild card we can also get other info for look up later
SELECT * FROM people
WHERE people.passport_number IN
(SELECT passengers.passport_number FROM passengers
WHERE flight_id = 36);
-- id | name | phone_number | passport_number | license_plate
-- 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
-- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- 651714 | Edward | (328) 555-1152 | 1540955065 | 130LD9Z
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- 953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04
-- this is my current suspect list, I am now going to see if any of the
-- license plates match cars at the courhouse
SELECT * FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND year = 2020 AND activity = 'exit'
AND courthouse_security_logs.license_plate IN
(SELECT people.license_plate FROM people
WHERE people.passport_number IN
(SELECT passengers.passport_number FROM passengers
WHERE flight_id = 36));
-- id | year | month | day | hour | minute | activity | license_plate
-- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
-- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
-- 268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58
SELECT * FROM people
WHERE people.license_plate IN
(SELECT courthouse_security_logs.license_plate FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND year = 2020 AND activity = 'exit'
AND courthouse_security_logs.license_plate IN
(SELECT people.license_plate FROM people
WHERE people.passport_number IN
(SELECT passengers.passport_number FROM passengers
WHERE flight_id = 36)));
-- id | name | phone_number | passport_number | license_plate
-- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- current list of suspects
-- now going to check atm use before theift as per
-- --Eugene recognises the theif and seen them at an ATM on Fifer Street before theft
SELECT * FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2020 AND atm_location = 'Fifer Street';
-- id | account_number | year | month | day | atm_location | transaction_type | amount
-- 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 275 | 86363979 | 2020 | 7 | 28 | Fifer Street | deposit | 10
-- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35
-- now check if any of the transaction account numbers match suspect list
-- also change above query to only inlcude withdraw
SELECT DISTINCT(people.id), people.name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE bank_accounts.account_number IN
(SELECT atm_transactions.account_number FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2020 AND atm_location = 'Fifer Street'
AND transaction_type = 'withdraw');
-- id | name
-- 395717 | Bobby
-- 396669 | Elizabeth
-- 438727 | Victoria
-- 449774 | Madison
-- 458378 | Roy
-- 467400 | Danielle
-- 514354 | Russell
-- 686048 | Ernest
-- these are the people who withdrew from that atm on that day
-- this narrows suspect list down to three
-- I Don't think it is madison as 1106n58 left courthose a little too late
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- now we can search phone calls from just after the incident
SELECT * FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2020
AND caller = '(389) 555-5198';
SELECT * FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2020
AND caller = '(286) 555-6063';
SELECT * FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2020
AND caller = '(367) 555-5533';
-- Danielle doesn't have any calls that day but madison does
-- I don't think it is madision as she left the courtroom after 10 mins
-- ernest made 4 calls that day, only one under a minute
--id | caller | receiver | year | month | day | duration
--233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
-- which was to
SELECT * FROM people
WHERE phone_number = '(375) 555-8161';
--id | name | phone_number | passport_number | license_plate
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0
-- it could then be ernest with berthold as the accomplice

