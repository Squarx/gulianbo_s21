with female as (select p.name as pizzeria_name
                from person_visits
                         join pizzeria p on p.id = person_visits.pizzeria_id
                         join person p1 on p1.id = person_visits.person_id
                where p1.gender = 'female'),

     male as (select p.name as pizzeria_name
              from person_visits
                       join pizzeria p on p.id = person_visits.pizzeria_id
                       join person p1 on p1.id = person_visits.person_id
              where p1.gender = 'male'),
     exept_male as (select *
                    from female
                    except all
                    select *
                    from male),
     exept_female as (select *
                      from male
                      except all
                      select *
                      from female)
select *
from exept_male
union all
select *
from exept_female
order by pizzeria_name;
