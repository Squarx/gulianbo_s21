select address,
       p.name   as name,
       count(*) as count_of_orders
from person
         join person_order po on person.id = po.person_id
         join menu m on m.id = po.menu_id
         join pizzeria p on p.id = m.pizzeria_id
GROUP BY address, p.name
order by address, name;
