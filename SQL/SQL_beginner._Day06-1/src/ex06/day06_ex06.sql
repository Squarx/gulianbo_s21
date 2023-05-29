DROP SEQUENCE IF EXISTS seq_person_discounts CASCADE;
CREATE SEQUENCE seq_person_discounts START WITH 1;
DO $$
DECLARE
    Rows_cnt INT := (SELECT COUNT(*) FROM person_discounts);
BEGIN
    PERFORM setval('seq_person_discounts', Rows_cnt);
END $$;
ALTER TABLE person_discounts ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');
