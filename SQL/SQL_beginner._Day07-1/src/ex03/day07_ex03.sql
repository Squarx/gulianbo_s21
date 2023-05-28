WITH full_visit as (SELECT pz.id, pz.name, count(*) as count
                    FROM person_visits ps
                             right JOIN pizzeria pz on pz.id = ps.pizzeria_id
                    group by pz.id
                    order by id),
     full_order as (SELECT pz.id, pz.name, count(*) as count
                    from person_order pv
                        join menu m on m.id = pv.menu_id
                        right join pizzeria pz on m.pizzeria_id = pz.id
                    group by pz.id
                    order by id
)
select fo.name as name, fo.count + fv.count as total_count
from full_order fo
full join full_visit fv on fv.id = fo.id
ORDER BY total_count DESC, name;



