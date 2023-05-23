-- v1
INSERT INTO person_visits
VALUES ((SELECT MAX(id) + 1 FROM person_visits),
        (SELECT id FROM person WHERE name = 'Denis'),
        (SELECT id FROM pizzeria WHERE name = 'Dominos'),
        '2022-02-24');
INSERT INTO person_visits
VALUES ((SELECT MAX(id) + 1 FROM person_visits),
        (SELECT id FROM person WHERE name = 'Irina'),
        (SELECT id FROM pizzeria WHERE name = 'Dominos'),
        '2022-02-24');

-- v2
INSERT INTO person_visits
SELECT MAX(id) + 1,
       (SELECT id FROM person WHERE name = 'Denis'),
       (SELECT id FROM pizzeria WHERE name = 'Dominos'),
       DATE '2022-02-24'
FROM person_visits
UNION ALL
SELECT MAX(id) + 2,
       (SELECT id FROM person WHERE name = 'Irina'),
       (SELECT id FROM pizzeria WHERE name = 'Dominos'),
       DATE '2022-02-24'
FROM person_visits;

-- show
select * from person_visits order by id;


-- delete last
DELETE
FROM person_visits
WHERE id = (SELECT MAX(id)
            FROM person_visits);