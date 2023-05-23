select name
from pizzeria
where id not in (select pizzeria_id from person_visits);


select name
from pizzeria as pz
where not exists(select * from person_visits where pizzeria_id = pz.id)