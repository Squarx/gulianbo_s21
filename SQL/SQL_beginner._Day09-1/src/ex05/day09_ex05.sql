DROP FUNCTION IF EXISTS fnc_persons_female CASCADE;
DROP FUNCTION IF EXISTS fnc_persons_male CASCADE;
DROP FUNCTION IF EXISTS fnc_persons CASCADE;

CREATE FUNCTION fnc_persons(pgender VARCHAR DEFAULT 'female')
RETURNS TABLE (
    id      BIGINT,
    name    VARCHAR,
    age     INT,
    gender  VARCHAR,
    address VARCHAR
)
AS
$$
    SELECT p.id, p.name, p.age, p.gender, p.address
    FROM person p
    WHERE p.gender = pgender;
$$ LANGUAGE SQL;











--pgsql version

-- CREATE FUNCTION fnc_persons(pgender varchar DEFAULT 'female')
-- RETURNS TABLE (
--     id BIGINT,
--     name VARCHAR,
--     age INT,
--     gender VARCHAR,
--     address VARCHAR
-- )
-- AS $$
-- BEGIN
--     IF (pgender = 'male') THEN
--         RETURN QUERY SELECT p.id, p.name, p.age, p.gender, p.address
--                      FROM person p
--                      WHERE p.gender = 'male';
--     ELSE
--         RETURN QUERY SELECT p.id, p.name, p.age, p.gender, p.address
--                      FROM person p
--                      WHERE p.gender = 'female';
--     END IF;
-- END;
-- $$ LANGUAGE plpgsql;