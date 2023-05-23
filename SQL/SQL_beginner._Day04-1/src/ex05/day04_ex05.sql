CREATE OR REPLACE VIEW v_price_with_discount AS
SELECT p.name                     as name,
       m.pizza_name               as pizza_name,
       price,
       round(price - price * 0.1) as discount_price
from person_order
         join person p on person_order.person_id = p.id
         join menu m on person_order.menu_id = m.id
order by name, pizza_name;

select *
from v_price_with_discount;