select name
from person
union all
select  pizza_name as object_name
from menu
order by name;