-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year=2021 AND street= "Humphrey Street";

SELECT transcript FROM interviews
  WHERE day = 28 AND month = 7 AND year=2021 AND transcrpt LIKE "%bakery%";



SELECT name FROM people
Join bakery_security_logs ON bakery_security_logs.license_plate = people.license
WHERE day = 28 AND month = 7 AND year=2021 AND hour = 10 AND minute >= 15 AND minute <= 25
 AND activity = "exit";




SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions on atm_transactions.account_number =bank_accounts.account
WHERE day = 28 AND month = 7 AND year=2021 AND atm_location = "Legget Street";



SELECT name FROM people
JOIN phone_calls ON phone.calls_caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;




SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
   SELECT id FROM flights
   WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
     SELECT id FROM airports WHERE city = "Fiftyville")
   ORDER BY hour,minute
   LIMIT 1)

SELECT phone_number FROM people WHERE name = "Bruce";








































