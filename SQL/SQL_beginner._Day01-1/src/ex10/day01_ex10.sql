select p.name as person_name, m.pizza_name as pizza_name, pz.name as pizzeria_name
from person_order as po
         inner join menu m on po.menu_id = m.id
         inner join person p on po.person_id = p.id
         inner join pizzeria pz on m.pizzeria_id = pz.id
order by person_name, pizza_name, pizzeria_name;