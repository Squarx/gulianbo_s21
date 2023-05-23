select order_date,
       p.name || ' (age:' || p.age || ')'
           as person_information
from person_order
         inner join person p on person_order.person_id = p.id
order by order_date, person_information;