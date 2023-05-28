with task00 as (SELECT person_id, count(*) as count_of_visits
                from person_visits
                GROUP BY person_id
                ORDER BY count_of_visits DESC, person_id)
select  name, count_of_visits
from person
    join task00  on task00.person_id = person.id
ORDER BY count_of_visits DESC, name
FETCH NEXT 4 ROWS ONLY;