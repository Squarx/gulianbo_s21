select distinct p.name
from person_order po
         join person p on p.id = po.person_id
order by name;