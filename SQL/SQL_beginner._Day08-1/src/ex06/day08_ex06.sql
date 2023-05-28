-- Session #1 && #2
BEGIN TRANSACTION;
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #1
SELECT SUM(rating) FROM pizzeria;
-- Session #2
UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut';
COMMIT;

-- Session #1
SELECT SUM(rating) FROM pizzeria;
COMMIT;
-- Session #1 && #2
SELECT SUM(rating) FROM pizzeria;

