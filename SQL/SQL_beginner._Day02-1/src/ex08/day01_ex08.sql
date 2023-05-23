select distinct name
from person
         inner join person_order po on person.id = po.person_id
         inner join menu m on m.id = po.menu_id
where (gender = 'male') and (address = 'Moscow' or address = 'Samara')
  and (pizza_name = 'pepperoni pizza' or pizza_name = 'mushroom pizza')
order by name desc;
