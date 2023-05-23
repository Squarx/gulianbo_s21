select p.id    as person_id,
       p.name  as person_name,
       p.age,
       p.gender,
       p.address,
       pz.id   as pizzeria_id,
       pz.name as pizzeria_name,
       pz.rating
from person as p
         cross join
     pizzeria as pz
order by person_id,
         pizzeria_id;