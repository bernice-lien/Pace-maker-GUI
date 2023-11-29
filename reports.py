from fpdf import FPDF
pdf = FPDF()

# Add a page
pdf.add_page()

# set style and size of font 
# that you want in the pdf
pdf.set_font("Arial", size = 10)

# create a cell

pdf.cell(200, 10, txt = "Temporary Report", 
        ln = 1, align = 'C')

# add another cell
pdf.cell(200, 10, txt = "Patient: " + "login_name" ,ln = 2, align = 'C')
pdf.cell(200, 10, txt = "Institution: " + "McMaster University" ,ln = 2, align = 'C')
pdf.cell(200, 10, txt = "Device Model: " + "12.0   Serial Number: 00395012" ,ln = 2, align = 'C')
pdf.cell(200, 10, txt = "Software Version " + "6.1v   DCM Serial Number: 30194892" ,ln = 2, align = 'C')

# save the pdf with name .pdf
pdf.output("GFG.pdf")  