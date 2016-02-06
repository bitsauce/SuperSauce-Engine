//       ____  ____     ____                        _____             _            
// __  _|___ \|  _ \   / ___| __ _ _ __ ___   ___  | ____|_ __   __ _(_)_ __   ___ 
// \ \/ / __) | | | | | |  _ / _  |  _   _ \ / _ \ |  _| |  _ \ / _  | |  _ \ / _ \
//  >  < / __/| |_| | | |_| | (_| | | | | | |  __/ | |___| | | | (_| | | | | |  __/
// /_/\_\_____|____/   \____|\__ _|_| |_| |_|\___| |_____|_| |_|\__, |_|_| |_|\___|
//                                                              |___/     
//				Originally written by Marcus Loo Vergara (aka. Bitsauce)
//									2011-2015 (C)

#include <CGF/Common.h>
#include <CGF/Graphics/Texture.h>
#include <CGF/Graphics/Shader.h>

BEGIN_CGF_NAMESPACE

ResourceManager::ResourceManager(const string &resourceFile)
{
	// Load resource file
	if(util::fileExists(resourceFile))
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile(resourceFile.c_str());

		// Get root node
		tinyxml2::XMLNode *resourceNode = doc.FirstChildElement();
		if(!resourceNode)
		{
			LOG("Invalid resource file");
			return;
		}

		// For each context
		resourceNode = resourceNode->FirstChildElement();
		while(resourceNode)
		{
			// For each resource entry
			tinyxml2::XMLElement *name = resourceNode->FirstChildElement("name");

			// Get name and path
			if(name)
			{
				string type = resourceNode->Value();
				if(type == "texture")
				{
					tinyxml2::XMLElement *path = resourceNode->FirstChildElement("path");
					tinyxml2::XMLElement *premul = resourceNode->FirstChildElement("premultiplyAlpha");
					if(path)
					{
						m_resourceDesc[name->GetText()] =
							new TextureResourceDesc(
								name->GetText(),
								path->GetText(),
								premul && string(premul->GetText()) == "true"
								);
					}
				}
				else if(type == "font")
				{
					tinyxml2::XMLElement *path = resourceNode->FirstChildElement("path");
					tinyxml2::XMLElement *premul = resourceNode->FirstChildElement("premultiplyAlpha");
					if(path)
					{
						m_resourceDesc[name->GetText()] = new FontResourceDesc(
							name->GetText(),
							path->GetText(),
							premul && string(premul->GetText()) == "true"
							);
					}
				}
				else if(type == "shader")
				{
					tinyxml2::XMLElement *vertexFilePath = resourceNode->FirstChildElement("vertexFilePath");
					tinyxml2::XMLElement *fragmentFilePath = resourceNode->FirstChildElement("fragmentFilePath");
					if(vertexFilePath && fragmentFilePath)
					{
						m_resourceDesc[name->GetText()] = new ShaderResourceDesc(name->GetText(), vertexFilePath->GetText(), fragmentFilePath->GetText());
					}
				}
			}

			// Next resource
			resourceNode = resourceNode->NextSibling();
		}
	}
}

END_CGF_NAMESPACE