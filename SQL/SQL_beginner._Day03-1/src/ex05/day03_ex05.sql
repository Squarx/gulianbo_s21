with visits as (select p.name as person, pizzeria_id, pz.name as pizzeria_name
                from person p
                         join person_visits pv on p.id = pv.person_id
                         join pizzeria pz on pz.id = pizzeria_id
                where p.name = 'Andrey'),
     orders as (select p.name as person, pizzeria_id, pz.name as pizzeria_name
                from person p
                         join person_order po on p.id = po.person_id
                         join menu m on po.menu_id = m.id
                         join pizzeria pz on pz.id = m.pizzeria_id
                where p.name = 'Andrey')
select pizzeria_name
from visits
except all
(select pizzeria_name from orders);