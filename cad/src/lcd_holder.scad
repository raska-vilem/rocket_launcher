lcd_width = 21;
lcd_height = 16.6;
lcd_deepth = 4.6;
wall_thickness = 2.15;
hole_width = 25.3;
hole_height = 17.3;

difference() {
    union() {
        translate([0, 0, (lcd_deepth+wall_thickness)/2])
            cube([hole_width, hole_height, lcd_deepth+wall_thickness], center=true);
        
        translate([0, 0, 0.5])
            cube([hole_width, hole_height+4, 1], center=true);
    }

    translate([0, 0, 0])
        cube([lcd_width, lcd_height, 100], center=true);
}