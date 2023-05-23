select order_date as action_date,
       p.name     as person_name
from person_order
         inner join person p on person_id = p.id
intersect
select visit_date, p.name
from person_visits
         inner join person p on person_visits.person_id = p.id
order by action_date, person_name desc;
