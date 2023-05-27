-- CREATE INDEX idx_person_name ON person USING btree(UPPER(name));
set enable_seqscan = OFF;
DROP INDEX IF EXISTS idx_person_name;
CREATE INDEX idx_person_name ON person (UPPER(name));
EXPLAIN ANALYZE
SELECT *
FROM person
WHERE UPPER(name) = 'DMITRIY';