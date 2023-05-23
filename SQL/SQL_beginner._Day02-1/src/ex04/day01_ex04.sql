select pizza_name, pz.name as pizzeria_name, price
from menu inner join pizzeria pz on menu.pizzeria_id = pz.id where
pizza_name = 'mushroom pizza' or pizza_name = 'pepperoni pizza'
order by  pizza_name, pizzeria_name;

