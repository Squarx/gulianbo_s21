select p.name                         as name,
       m.pizza_name                   as pizza_name,
       price                          as price,
       price * (1 - (discount / 100)) as discount_price,
       pz.name                        as pizzeria_name
from person p
         join person_discounts pd on p.id = pd.person_id
         join pizzeria pz on pd.pizzeria_id = pz.id
         join menu m on pz.id = m.pizzeria_id
         join person_order po on m.id = po.menu_id and p.id = po.person_id
order by name, pizza_name;
