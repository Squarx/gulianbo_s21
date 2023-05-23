with female as (select pz.name as  pizzeria_name from person_order
    join person p on p.id = person_order.person_id
    join menu m on person_order.menu_id = m.id
    join pizzeria pz on pz.id = m.pizzeria_id
where gender = 'female'),
    male as (select pz.name as  pizzeria_name from person_order
    join person p on p.id = person_order.person_id
    join menu m on person_order.menu_id = m.id
    join pizzeria pz on pz.id = m.pizzeria_id
where gender = 'male'),
      exept_male as (select *
                    from female
                    except
                    select *
                    from male),
     exept_female as (select *
                      from male
                      except
                      select *
                      from female)
select * from exept_male union all select * from exept_female
order by 1;
