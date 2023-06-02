DROP FUNCTION IF EXISTS fnc_person_visits_and_eats_on_date;
CREATE FUNCTION fnc_person_visits_and_eats_on_date (
    pperson VARCHAR DEFAULT 'Dmitriy',
    pprice BIGINT DEFAULT 500,
    pdate DATE DEFAULT '2022-01-08'::date)
RETURNS TABLE
(
    pizzria_name VARCHAR
)
AS
$$
    SELECT  pz.name
    FROM person_visits
             INNER JOIN person p ON p.id = person_visits.person_id
             INNER JOIN pizzeria pz ON pz.id = person_visits.pizzeria_id
             INNER JOIN menu m ON pz.id = m.pizzeria_id
    WHERE p.name = pperson AND visit_date = pdate AND price < pprice
$$ LANGUAGE SQL;
