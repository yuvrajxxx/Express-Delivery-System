<?php
// Get the user input from the form
$source_node = $_POST["source_node"];
$destination_node = $_POST["destination_node"];
$num_items = $_POST["num_items"];

// Call the express_delivery_system program with the user input as arguments
$output = shell_exec("./express_delivery_system $source_node $destination_node $num_items");

// Extract the shortest path and shipping cost from the output
list($shortest_path, $shipping_cost) = explode("\n", $output);

// Display the shortest path and shipping cost on the web page
echo "<p>Shortest path: $shortest_path</p>";
echo "<p>Shipping cost: $shipping_cost</p>";
?>
