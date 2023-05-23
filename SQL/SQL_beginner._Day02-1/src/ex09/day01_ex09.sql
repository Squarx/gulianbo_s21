select name
from person inner join person_order po on person.id = po.person_id
inner join menu m on m.id = po.menu_id
where gender='female'
and (pizza_name = 'pepperoni pizza' or  pizza_name = 'cheese pizza')
group by name
having count(pizza_name) > 1
order by name;