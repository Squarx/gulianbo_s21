with full_menue_CTE as (select pizza_name, pz.name as pizzeria_name, pizzeria_id, price
                        from menu
                                 join pizzeria pz on menu.pizzeria_id = pz.id)
select f1.pizza_name as pizza_name,
       f1.pizzeria_name as pizzeria_name_1,
       f2.pizzeria_name as pizzeria_name_2,
       f1.price as price
from full_menue_CTE f1
         inner join full_menue_CTE f2 on f1.price = f2.price
    and f1.pizza_name = f2.pizza_name
    and f1.pizzeria_id > f2.pizzeria_id
order by pizza_name;
