select id as object_id, pizza_name as object_name
from menu
union all
select id, name
from person
order by object_id, object_name;