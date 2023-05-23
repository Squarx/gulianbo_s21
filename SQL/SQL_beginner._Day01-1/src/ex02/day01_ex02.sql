-- select pizza_name, count(pizza_name) from menu group by pizza_name
select pizza_name from menu
union
select pizza_name from menu
order by pizza_name desc;