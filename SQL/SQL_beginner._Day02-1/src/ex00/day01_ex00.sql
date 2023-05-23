select name, ratingA
from pizzeria
         left join person_visits pv on pizzeria.id = pv.pizzeria_id
where pv.pizzeria_id IS NULL