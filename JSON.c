
try:
	import json
except ImportError:
	try:
		import simplejson as json
	except ImportError:
		from django.utils import simplejson as json

class ApiClient(object):
	"""
	A client for accessing a RESTful API
	"""
	def __init__(self, api_key, api_secret, api_uri):
		"""
		Create a RESTful API client.
		"""
		self.api_uri	= api_uri
		self.api_key	= api_key
		self.api_secret = api_secret

	def version(self):
		return __version__




	@staticmethod
	def merge_dicts(*dict_args):
		result = {}
		for dictionary in dict_args:
			result.update(dictionary)

		return result

	def request(self, method, path, data = {}, headers = {}):
		from requests import request

		url = '{0}{1}'.format(self.api_uri, path)
		params = {}
		headers = self.merge_dicts(self.set_headers(), headers)

		if method == "GET":
			params.update(data)
			return request(method, url, headers=headers, params=params)
		else:
			return request(method, url, headers=headers, params=params, data=json.dumps(data))

	def post(self, path, data = {}):
		return Response(self.request("POST", path, data, {'Content-Type': 'application/json'}))

	def get(self, path, data = {}):
		return Response(self.request("GET", path, data))

	def put(self, path, data = {}):
		return Response(self.request("PUT", path, data, {'Content-Type': 'application/json'}))

	def delete(self, path, data = {}):
		return Response(self.request("DELETE", path, data))

class Response(object):
	def __init__(self, response):
		self.response = response

		try:
			self.content = self.response.json()
		except ValueError:
			self.content = self.response.text

	def ok(self):
		import requests
		return self.response.status_code == requests.codes.ok

	def errors(self):
		if self.ok():
			return {}

		errors = self.content

		if(not isinstance(errors, dict)):
			errors = {"error": errors} # convert to dict for consistency
		elif('errors' in errors):
			errors = errors['errors']

		return errors

	def __getitem__(self, key):
return self.content[key]