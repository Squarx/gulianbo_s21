select pizza_name, p.name as pizzeria_name
from person
         inner join person_order po on person.id = po.person_id
         inner join menu m on po.menu_id = m.id
         inner join pizzeria p on m.pizzeria_id = p.id
where person.name = 'Denis'
   or person.name = 'Anna'
order by pizza_name, pizzeria_name;