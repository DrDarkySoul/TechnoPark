from cgi import parse_qsl, escape
from pprint import pformat

def get_list_length(args):
	return sum(len(element) for element in args)

def application(env, start_response):

	page = []

	page.append("""<h1> Hello World </h1>""")

	page.append("""<h2>POST FORM:</h2>""")
	page.append("""<form method="Post">""")
	page.append("""<br>""")
	page.append("""<input type="text" name="post_parameter_1">""")
	page.append("""<br>""")
	page.append("""<input type="text" name="post_parameter_2">""")
	page.append("""<br>""")
	page.append("""<input type="submit">""")
	page.append("""</form>""")

        page.append("""<h2>GET FORM:</h2>""")
        page.append("""<form method="Get">""")
        page.append("""<input type="text" name="get_parameter_1">""")
	page.append("""<br>""")
        page.append("""<input type="text" name="get_parameter_2">""")
	page.append("""<br>""")
        page.append("""<input type="submit">""")
        page.append("""</form""")

	page.append("""<br>""")

    	if env['REQUEST_METHOD'] == 'POST':

		try:
                	request_body_size = int(env.get('CONTENT_LENGTH', 0))
       		except (ValueError):
                	request_body_size = 0

		request_body = env['wsgi.input'].read(request_body_size)

		request_parse = parse_qsl(request_body)

        	page.append("""<h2>POST REQUEST:</h2>""")

		for parameters in request_parse:
			page.append("=".join(parameters))
			page.append("""<br>""")

	if env['REQUEST_METHOD'] == 'GET':
       		if env['QUERY_STRING'] != '':

			request_parse = parse_qsl(env['QUERY_STRING'])

            		page.append("""<h2>GET REQUEST:</h2>""")

			for parameters in request_parse:
                		page.append("=".join(parameters))
                		page.append("<br>")

	start_response('200 OK', [('Content-Type', 'text/html'),('Content-Length', get_list_length(page))])
        return page
