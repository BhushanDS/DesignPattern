import xml.etree.ElementTree as ET
import csv
import sys

def extract_test_data(root):
    test_data = []

    # Loop through test elements
    for test_elem in root.findall(".//Test"):
        test_id  = test_elem.attrib.get("id", "")
        name     = test_elem.attrib.get("name", "")
        category = test_elem.attrib.get("category", "")
        link     = test_elem.attrib.get("link", "")
        status = test_elem.attrib.get("status", "")
        executionTime = test_elem.attrib.get("executionTime", "")

        test_data.append([test_id, name, category, link, status, executionTime])

    return test_data

def main(xml_file_path, csv_filename):
    # Parse the XML
    tree = ET.parse(xml_file_path)
    root = tree.getroot()

    # Write to CSV
    with open(csv_filename, mode='w', newline='') as csv_file:
        csv_writer = csv.writer(csv_file)

        # Write header row
        csv_writer.writerow(["Test id", "Name", "Catagory", "Link", "Status", "ExecutionTime"])

        # Extract and write test data to CSV
        test_data = extract_test_data(root)
        csv_writer.writerows(test_data)

    print(f"CSV file '{csv_filename}' has been created.")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <xml_file_path> <csv_filename>")
        sys.exit(1)

    xml_file_path = sys.argv[1]
    csv_filename = sys.argv[2]

    main(xml_file_path, csv_filename)
