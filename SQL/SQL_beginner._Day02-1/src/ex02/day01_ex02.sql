SELECT COALESCE(p.name, '-')        AS person_name,
       pv.visit_date                AS visit_date,
       COALESCE(pizzeria.name, '-') AS pizzeria_name
FROM pizzeria
         LEFT JOIN person_visits pv ON pizzeria.id = pv.pizzeria_id
    AND pv.visit_date BETWEEN '2022-01-01' AND '2022-01-03'
         full outer JOIN person p ON pv.person_id = p.id
ORDER BY person_name, visit_date, pizzeria_name;