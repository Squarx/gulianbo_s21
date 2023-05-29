CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS TRIGGER AS
$trg_person_audit$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO person_audit (type_event, row_id, name, age, gender, address)
        VALUES ('D', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address);
        RETURN NULL;
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO person_audit (type_event, row_id, name, age, gender, address)
        VALUES ('U', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address);
        RETURN NEW;
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO person_audit (type_event, row_id, name, age, gender, address)
        VALUES ('I', NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address);
        RETURN NEW;
    END IF;
END;
$trg_person_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_person_audit
    AFTER INSERT OR UPDATE OR DELETE
    ON person
    FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_audit();

DROP FUNCTION IF EXISTS fnc_trg_person_insert_audit CASCADE;
DROP FUNCTION IF EXISTS fnc_trg_person_update_audit CASCADE;
DROP FUNCTION IF EXISTS fnc_trg_person_delete_audit CASCADE;
TRUNCATE TABLE person_audit;

INSERT INTO person(id, name, age, gender, address)
VALUES (10, 'Damir', 22, 'male', 'Irkutsk');
UPDATE person
SET name = 'Bulat'
WHERE id = 10;
UPDATE person
SET name = 'Damir'
WHERE id = 10;
DELETE
FROM person
WHERE id = 10;
select * from person_audit;