from django.shortcuts import render
from django.http import HttpResponse
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger

questions = []
answers = []

for i in xrange(1,30):
	questions.append({'title': str(i) + ' ) Title: ' + 'Lorem ipsum dolor sit amet',
	 'id': i,
	 'text': 'text' + str(i) + 
	 'consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',})

for i in xrange(1,5):
	answers.append({'id': i,
	 'text': 'text' + str(i) + 
	 'consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',})

def index(request, id = '0'):

	paginator = Paginator(questions, 5)

	page = request.GET.get('page')

	try:
		question_paginator = paginator.page(page)
	
	except PageNotAnInteger:
		question_paginator = paginator.page(1)
	
	except EmptyPage:
		question_paginator = paginator.page(paginator.num_pages)

	return render(request, 'Ask/new.html' , {'id': id, 'question_list': question_paginator})

def login(request):
	return render(request, 'Ask/login.html')

def signup(request):
	return render(request, 'Ask/signup.html')

def ask(request):
	return render(request, 'Ask/ask.html')

def error(request):
	return render(request, 'Ask/error.html')

def hot(request, id = '0'):

	paginator = Paginator(questions, 5)

	page = request.GET.get('page')

	try:
		question_paginator = paginator.page(page)
	
	except PageNotAnInteger:
		question_paginator = paginator.page(1)
	
	except EmptyPage:
		question_paginator = paginator.page(paginator.num_pages)

	return render(request, 'Ask/hot.html', {'id': id, 'question_list': question_paginator})

def tag(request, tag = ' ', id = '0'):

	paginator = Paginator(questions, 5)

	page = request.GET.get('page')

	try:
		question_paginator = paginator.page(page)
	
	except PageNotAnInteger:
		question_paginator = paginator.page(1)
	
	except EmptyPage:
		question_paginator = paginator.page(paginator.num_pages)

	return render(request, 'Ask/tag.html', {'id': id, 'tag': tag, 'question_list': question_paginator})

def question(request, id = '0'):
	return render(request, 'Ask/question.html', {'id': id, 'answers_list': answers})
