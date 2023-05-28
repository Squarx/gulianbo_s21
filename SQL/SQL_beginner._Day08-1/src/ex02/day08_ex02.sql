-- Session #1 && #2
BEGIN TRANSACTION;
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #1 && #2
SELECT * FROM pizzeria;

-- Session #1
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut';
-- Session #2
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
/* 
    Не удалось сериализовать доступ из-за параллельного изменения
*/
-- Session #1 && #2
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut';