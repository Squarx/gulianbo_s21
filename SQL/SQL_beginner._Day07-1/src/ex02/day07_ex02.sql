WITH top3_visit as (SELECT name, count, action_type
                    FROM (SELECT pz.name                                    as name,
                                 count(*)                                   as count,
                                 'visit'                                    as action_type,
                                 ROW_NUMBER() OVER (ORDER BY count(*) DESC) AS count_row
                          FROM person_visits ps
                                   INNER JOIN pizzeria pz on pz.id = ps.pizzeria_id
                          GROUP BY name) subquery
                    WHERE count_row < 4),
     top3_order as (SELECT pz.name as name, count(*) as count, 'order' as action_type
                    FROM person_order
                             join menu m on person_order.menu_id = m.id
                             join pizzeria pz on m.pizzeria_id = pz.id
                    GROUP BY pz.name
                    ORDER BY count DESC
                    LIMIT 3),
    top6 as (
    SELECT *
    from top3_visit
    union all
    SELECT *
    from top3_order
    )
select * from top6
order by action_type, count DESC;
--
-- select * from person_visits;