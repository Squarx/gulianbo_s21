/*
1. Create a new user
-  psql -U postgres
- CREATE ROLE gulianbo WITH
	LOGIN
	SUPERUSER
	CREATEDB
	CREATEROLE
	INHERIT
	NOREPLICATION
	CONNECTION LIMIT -1
	PASSWORD 'xxxxx';
2. Open 2 PSQL tool
    For postgres:  \c Day08
    For gulianbo: psql -U gulianbo  -d Day08
    \! cls - clear screen
*/


-- session1 && #2
BEGIN TRANSACTION;
SHOW TRANSACTION ISOLATION LEVEL;

-- session1
UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut';
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut';
-- session2
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut';

-- session1
COMMIT;
-- session2
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut';
COMMIT;