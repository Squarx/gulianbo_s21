-- Session #1 && #2
BEGIN TRANSACTION;
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #1
UPDATE pizzeria SET rating = 1.1 WHERE id = 1;
-- Session #2
UPDATE pizzeria SET rating = 2.1 WHERE id = 2;

-- Session #1
UPDATE pizzeria SET rating = 2.2 WHERE id = 2;
-- Session #2
UPDATE pizzeria SET rating = 1.2 WHERE id = 1;

-- Session #1
COMMIT;
-- Session #2
COMMIT;
