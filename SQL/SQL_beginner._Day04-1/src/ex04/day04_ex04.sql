CREATE OR REPLACE VIEW v_symmetric_union AS
WITH R AS (SELECT *
           FROM person_visits
           WHERE visit_date = '2022-01-02'),
     S AS (SELECT *
           FROM person_visits
           WHERE visit_date = '2022-01-06'),
     R_S AS (SELECT person_id
             FROM R
             EXCEPT
             SELECT person_id
             FROM S),
     S_R AS (SELECT person_id
             FROM S
             EXCEPT
             SELECT person_id
             FROM R)
SELECT person_id
FROM R_S
UNION
SELECT person_id
FROM S_R
ORDER BY person_id;

select *
from v_symmetric_union;