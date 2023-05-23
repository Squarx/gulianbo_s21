select order_date,
       p.name || ' (age:' || p.age || ')'
           as person_information
from person as p
         natural join (select order_date, person_id as id from person_order) as tmp
order by order_date, person_information;
