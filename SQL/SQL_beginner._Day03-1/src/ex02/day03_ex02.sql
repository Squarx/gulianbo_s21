with id_exept as (select id as menu_id
                  from menu
                  except
                  select menu_id
                  from person_order)
select pizza_name, price, p.name as pizzeria_name
from menu
         join pizzeria p on p.id = menu.pizzeria_id
where menu.id in (select menu_id from id_exept)
order by pizza_name, price;