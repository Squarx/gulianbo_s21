select p.name                         as name,
       m.pizza_name                   as pizza_name,
       price                          as price,
       price * (1 - (discount / 100)) as discount_price,
       pz.name                        as pizzeria_name
from person_order
         join person_discounts pd on person_order.person_id = pd.person_id
         join person p on p.id = pd.person_id
         join menu m on m.id = person_order.menu_id
         join pizzeria pz on m.pizzeria_id = pz.id
order by name, pizza_name;