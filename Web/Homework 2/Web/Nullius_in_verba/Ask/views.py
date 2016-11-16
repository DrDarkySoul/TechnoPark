from django.shortcuts import render

# Create your views here.
from django.views.decorators.csrf import ensure_csrf_cookie
from django.http import HttpResponse

@ensure_csrf_cookie
def index(request):

	page = []

	page.append("""<h1> Hello World </h1>""")

        page.append("""<h2>GET FORM:</h2>""")
        page.append("""<form method="Get">""")
        page.append("""<input type="text" name="get_parameter_1">""")
        page.append("""<br>""")
        page.append("""<input type="text" name="get_parameter_2">""")
        page.append("""<br>""")
        page.append("""<input type="submit">""")
        page.append("""</form""")

        page.append("""<br>""")

	if request.method == 'GET':
		page.append("""<h2>GET REQUEST:</h2>""")
		for key, value in request.GET.iteritems():
    			page.append("{} {}".format(key, value))
			page.append("""<br>""")

    	return HttpResponse(page)
