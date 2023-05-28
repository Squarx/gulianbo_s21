with prices as (
    select pz.name,
       round(avg(price), 2) as average_price_menue,
       max(price) as max_price,
       min(price) as min_price
       from menu  join pizzeria pz on menu.pizzeria_id = pz.id
group by pz.id
),
      full_order as (SELECT pz.id, pz.name as pizzeria_name, count( pz.id) as count,
                        round(avg(price), 2) as average_price_orders
                         from person_order pv
                                  join menu m on m.id = pv.menu_id
                                join pizzeria pz on m.pizzeria_id = pz.id
                         group by pz.id
                         order by id)
select name,
       fo.count as count_of_orders,
        average_price_orders as average_price,
        max_price,
        min_price
       from prices join full_order fo on fo.pizzeria_name = name
order by name;


select * from person_order join menu m on m.id = person_order.menu_id
right join pizzeria p on p.id = m.pizzeria_id
where p.name = 'DoDo Pizza';