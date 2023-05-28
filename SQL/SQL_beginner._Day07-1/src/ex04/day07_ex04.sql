SELECT p.name as name , count(pizzeria_id) as count
FROM person_visits ps
         right JOIN person p on ps.person_id = p.id
group by p.name
having count(pizzeria_id) > 3
order by count;

