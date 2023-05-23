select id as  menu_id from menu
except
select menu_id from person_order
order by menu_id;
