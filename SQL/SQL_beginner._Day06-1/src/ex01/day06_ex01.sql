WITH name_cnt_order as (select p.id as person_id, pz.id as pizzeria_id, count(p.id) as amount_of_order
                        from person_order
                                 join person p on person_order.person_id = p.id
                                 join menu m on m.id = person_order.menu_id
                                 join pizzeria pz on pz.id = m.pizzeria_id
                        group by p.id, pz.id
                        order by person_id, pizzeria_id, amount_of_order),

    person_pizzeria_discout as (
        select person_id, pizzeria_id,
       CASE
           WHEN amount_of_order = 1 then 10.5
           WHEN amount_of_order = 2 then 22
           ELSE 30
           END as discount
from name_cnt_order
)
INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT ROW_NUMBER() OVER () AS id, person_id, pizzeria_id, discount
FROM person_pizzeria_discout;
